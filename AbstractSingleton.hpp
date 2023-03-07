#include <type_traits>

class AbstractSingleton
{
public:
    // enabled if T is not AbstractSingleton and has GetInstance() member function
    template<typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, AbstractSingleton>
        && std::is_same_v<decltype(std::declval<T>().GetInstance()), T*>>>
    static T *GetInstance()
    {
        return T::GetInstance();
    }

    virtual ~AbstractSingleton() = default;

protected:
    AbstractSingleton() = default;

private:
    AbstractSingleton(const AbstractSingleton &) = delete;
    AbstractSingleton(AbstractSingleton &&) = delete;
    AbstractSingleton &operator=(const AbstractSingleton &) = delete;
    AbstractSingleton &operator=(AbstractSingleton &&) = delete;

};