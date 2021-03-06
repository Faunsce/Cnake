#pragma once
#include <SFML/Graphics.hpp>
#include <mutex>

enum struct ModeOption
{
	None,
	Intro,
	Menu,
	Game,
	Settings,
	Paused,
	Lose,
	One
};

enum struct ModeAction
{
	None,
	Add,
	DropTo
};


class Mode
{
public:
	Mode(std::string, std::mutex*, ModeOption);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) = 0;
	ModeOption type() { return ModeType; };
protected:
	void pushObject(std::string, sf::RectangleShape, std::string);
	void popObject(std::string);
public:
	std::vector<sf::Drawable*> screenObjects;
protected:
	std::map<std::string, sf::RectangleShape> screenObjectsMap;
	std::map<std::string, sf::Texture> objectTextures;
	std::mutex* mut;
	ModeOption ModeType;
	sf::Time timeBank;
	static float ratio;
};