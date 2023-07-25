#include <Fallen/Layer.h>
#include <Fallen/Scene/Entity.h>

#include <vector>

class GameLayer : public Layer
{
    public:
    GameLayer();
    ~GameLayer();

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate() override;
    void OnEvent(Event& event) override;

    private:
    std::vector<Entity*> m_Entities;
};
