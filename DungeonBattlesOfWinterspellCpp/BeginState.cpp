#include "BeginState.h"

void BeginState::Begin() {

	RenderSFMLGraphics();

	ctx_->SetAct(ActState::One);
	ctx_->SetState(GameState::LoadAct);
	ctx_->SetEventState(EventState::None);
}

void BeginState::RenderSFMLGraphics() {

	//sf::RenderWindow window(sf::VideoMode(1200, 1000), "My Game", sf::Style::Default);
//window.setFramerateLimit(60); // Limit the framerate to 60 FPS

//sf::Texture texture;
//if (!texture.loadFromFile("../images/brickwall.png")) {
//	// Handle error here
//	// For example, you can print an error message or throw an exception
//}

//sf::Sprite sprite;
//sprite.setTexture(texture);

//// Inside the game loop
//window.clear();
//window.draw(sprite);
//window.display();

}