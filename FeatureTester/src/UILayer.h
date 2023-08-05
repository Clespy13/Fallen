#include <Fallen/Layer.h>

class UILayer : public Layer
{
    public:
    UILayer();
    ~UILayer();

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(TimeStep ts) override;
    void OnEvent(Event& event) override;

    private:
};
