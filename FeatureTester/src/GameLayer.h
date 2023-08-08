#include <Fallen/Layer.h>
#include <Fallen/Scene/Entity.h>
#include <Fallen/Time.h>
#include <Fallen/Scene/Scene.h>

#include <vector>

class GameLayer : public Layer
{
    public:
    GameLayer();
    ~GameLayer();

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(TimeStep ts) override;
    void OnEvent(Event& event) override;

    Scene* m_Scene;

    static GameLayer& GetLayer() { return *s_Instance; };

    private:
    std::vector<Entity*> m_Entities;
    static GameLayer* s_Instance;
};
