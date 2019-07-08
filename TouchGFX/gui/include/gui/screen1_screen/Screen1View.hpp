#ifndef SCREEN1_VIEW_HPP
#define SCREEN1_VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Button.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void buttonClicked();
private:
	static const int NUMBER_OF_SLIDE_MENUS = 2;
	static const int NUMBER_OF_MENU_ITEM_BUTTONS = 4;
	static const int NUMBER_OF_MENU_ITEM_TOGGLE_BUTTONS = 4;
	
	SlideMenu slideMenus[NUMBER_OF_SLIDE_MENUS];
	ToggleButton bottomSlideMenuItems[NUMBER_OF_MENU_ITEM_TOGGLE_BUTTONS];
	ToggleButton topSlideMenuItems[NUMBER_OF_MENU_ITEM_TOGGLE_BUTTONS];
	
	Callback<Screen1View, const SlideMenu&> slideMenuStateChangedCallback;
	void slideMenuStateChangedHandler(const SlideMenu& slideMenu);
	
	Callback<Screen1View, const AbstractButton&> buttonClickedCallback;
	void buttonClickedHandler(const AbstractButton& button);
	
	
protected:
    bool imagevisible;
};

#endif // SCREEN1_VIEW_HPP
