#include <Fallen/Layer.h>

class UILayer : public Layer
{
    public:
    UILayer();
    ~UILayer();

    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate() override;
    void OnEvent(Event& event) override;

    private:
};
