#include "kkpch.h"
#include "Text.h"
#include "Text/TextLoader.h"
#include "Text/TextManager.h"
//#include "GLFW/glfw3.h" // Switch to chrono

namespace Koko
{
	Text::Text() noexcept
		: m_Data("Arial", "Blank Text"), m_Created(false)
	{

	}

	Text::Text(const TextData& data)
		: m_Data(data), m_Created(false)
	{

	}

	void Text::CreateMesh()
	{
		if (!m_Created)
		{
			LoadText();
			m_Vertices = TextManager::GetFont(m_Data.Font)->LoadText(m_Data);
			m_Created = true;
		}
	}

	void Text::LoadText()
	{
		m_Data.TextString = LoadTextString(std::to_string(m_Data.ID));
	}

	/*void Text::HandleInput(const std::string& input)
	{
		if (input == "Delete")
		{
			RemoveLetter();
			return;
		}

		if (input == "Space")
		{
			AddLetter(" ");
			return;
		}

		if (input != "")
		{
			AddLetter(input);
			return;
		}
	}*/

	/*void Text::Update()
	{
		if (m_UpdateNeeded)
		{
			if (m_TargetTime > 0.0f)
			{
				m_Time = (float)glfwGetTime();
				if (m_TargetTime - m_Time <= 0.0f)
				{
					Remove();
					m_UpdateNeeded = true;
				}
			}
			else
			{
				m_UpdateNeeded = false;
			}

		}
	}

	bool Text::Continue()
	{
		return true;
	}*/

	/*if (m_KeyString == "EditorMenuLoadSlot")
		{
			//std::fstream fs("Resources/Data/Level" + std::to_string(m_KeyNumber) + ".xml");
			if (fs.good())
			{
				std::string line;
				while (line != "/Name")
				{
					std::getline(fs, line, '<');
					std::getline(fs, line, '>');
					if (line.find("Name") != std::string::npos)
					{
						std::string text;
						std::getline(fs, text, '<');
						m_TextString = text;
						return;
					}
				}
			}
		}
	
		if (m_KeyString.empty())
		{
			return;
		}
	
		//m_TextString = LoadString(GetKey());
	
	}*/

	/*
	Text* Text::SetLineSize(float size)
	{
		m_LineMaxSize = size / 100.0f;
		return this;
	}
		
	Text* Text::SetKey(const std::string& key)
	{
		m_KeyString = key;
		m_Created = false;

		return this;
	}

	Text* Text::SetKeyNumber(unsigned int number)
	{
		m_KeyNumber = number;
		m_Created = false;

		return this;
	}

	Text* Text::AddLetter(const std::string& letter)
	{
		m_TextString.append(letter);

		m_Created = false;

		return this;
	}

	Text* Text::RemoveLetter()
	{
		if (m_TextString.size() >= 1)
		{
			m_TextString.pop_back();
		}

		m_Created = false;

		return this;
	}

	Text* Text::SetTime(float time)
	{
		m_TargetTime = (float)glfwGetTime() + time;
		m_UpdateNeeded = true;

		return this;
	}*/

}