#include "MenuState.h"

#include "Koko/Layer/UILayer.h"

MenuState::MenuState(const std::string& fileName)
	: Koko::State(fileName)
{
	
}

MenuState::~MenuState()
{

}

bool MenuState::OnEvent(Koko::Event& e)
{
	for (int it = m_LayerStack.size() - 1; it >= 0; --it)
	{
		m_LayerStack[it]->OnEvent(e);
		if (e.Handled)
		{
			return true;
		}
	}

	NotifyLayers();

	return false;
}

void MenuState::OnUpdate(Koko::Event& e)
{

}

void MenuState::Render()
{
	m_Renderer->Render(m_LayerStack);
}

void MenuState::Notify(Stack<State>* stack)
{
	//TODO: Change to action
	if (remove)
	{
		stack->Listen(Action::StateRemove);
		//stack->PopState();
	}
}

void MenuState::NotifyLayers()
{
	for (int i = 0; i < m_LayerStack.size(); ++i)
	{
		m_LayerStack[i]->Notify(this);
		if (m_LayerStack[i]->updatestate == Koko::Entity::State::Remove)
		{
			m_LayerStack.Pop(m_LayerStack[i]);
			--i;
		}
	}
}

void MenuState::ReceiveAction(Action action)
{
	if (action == Action::StateRemove)
	{
		remove = true;
	}

	if (action == Action::LayerRemove)
	{
		m_LayerStack.Pop();
	}
}