#include "AbstractSingleton.hpp"
#include <iostream>
#include <mutex>

class ConcreteSingleton : public AbstractSingleton
{
public:
    static ConcreteSingleton *GetInstance()
    {
        std::call_once(m_initFlag, []{ m_instance.reset(new ConcreteSingleton); });
        return m_instance.get();
    }

    virtual ~ConcreteSingleton() override
    {
        std::cout << "~ConcreteSingleton()" << std::endl;
    }

protected:
    ConcreteSingleton()
    {
        std::cout << "ConcreteSingleton()" << std::endl;
    }

protected:
    static std::unique_ptr<ConcreteSingleton> m_instance;
    static std::once_flag m_initFlag;

private:
    ConcreteSingleton(const ConcreteSingleton &) = delete;
    ConcreteSingleton(ConcreteSingleton &&) = delete;
    ConcreteSingleton &operator=(const ConcreteSingleton &) = delete;
    ConcreteSingleton &operator=(ConcreteSingleton &&) = delete;
};
std::unique_ptr<ConcreteSingleton> ConcreteSingleton::m_instance = nullptr;
std::once_flag ConcreteSingleton::m_initFlag;