#ifndef UI_LAYER_H
#define UI_LAYER_H
#include "Layer.h"
#include "Koko/Event/MouseEvent.h"
#include "Koko/Event/Action.h"

namespace Koko
{
	class UILayer : public Layer
	{
	private:
		std::vector<Action> m_Actions;
		Entity::State m_State = Entity::State::None;

	public:
		UILayer();
		~UILayer();

		void OnAttach() override;
		void OnUpdate()	override;
		void OnEvent(Event& e) override;

		void Notify(State* state) override;

	private:
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);

	};
}

#endif