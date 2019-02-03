#ifndef UI_ENTITY_H
#define UI_ENTITY_H
#include "Entity/Entity.h"

class UIEntity : public Entity
{
protected:
	std::vector<Entity*> m_Entities;

public:
	virtual bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e) override;
	virtual bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e) override;

	void AddEntity(Entity* entity);
	void PopEntity(Entity* entity);
};

#endif