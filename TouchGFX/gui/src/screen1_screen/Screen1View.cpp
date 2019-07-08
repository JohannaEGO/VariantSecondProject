#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <BitmapDatabase.hpp>

Screen1View::Screen1View() : slideMenuStateChangedCallback(this, &Screen1View::slideMenuStateChangedHandler),
							buttonClickedCallback(this, &Screen1View::buttonClickedHandler),
							imagevisible(true)
												 
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", TypedText(T_CUSTOMERCTEXT).getText());
	textArea2.invalidate();
	
	//setup Slide menus
	int buttonOverlapWithBackground = 6; //pixels
	
	//bottom slide menu
	//setup: north/east/south/west , background image, button to pop up menu, button pressed to pop up menu..
	slideMenus[0].setup(SlideMenu::NORTH, Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BACKGROUND_ID), Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BUTTON_ID), Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BUTTON_ID), 0, Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BUTTON_ID).getHeight() - buttonOverlapWithBackground, (Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BACKGROUND_ID).getWidth() - Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BUTTON_ID).getWidth()) / 2, 0);
	//set x and  position of menu
	slideMenus[0].setXY(0, HAL::DISPLAY_HEIGHT - slideMenus[0].getHeight());
	//set what is visible when collapsed
	slideMenus[0].setVisiblePixelsWhenCollapsed(Bitmap(BITMAP_BOTTOM_SLIDE_MENU_BUTTON_ID).getHeight());
	//set menu callback
	slideMenus[0].setStateChangedCallback(slideMenuStateChangedCallback);
	add(slideMenus[0]);
	
	// Setup buttons for the slide menu
    bottomSlideMenuItems[0].setBitmaps(Bitmap(BITMAP_MENU_BUTTON_00_ID), Bitmap(BITMAP_MENU_BUTTON_PRESSED_00_ID));
    bottomSlideMenuItems[1].setBitmaps(Bitmap(BITMAP_MENU_BUTTON_01_ID), Bitmap(BITMAP_MENU_BUTTON_PRESSED_01_ID));
    bottomSlideMenuItems[2].setBitmaps(Bitmap(BITMAP_MENU_BUTTON_02_ID), Bitmap(BITMAP_MENU_BUTTON_PRESSED_02_ID));
    bottomSlideMenuItems[3].setBitmaps(Bitmap(BITMAP_MENU_BUTTON_03_ID), Bitmap(BITMAP_MENU_BUTTON_PRESSED_03_ID));
    bottomSlideMenuItems[4].setBitmaps(Bitmap(BITMAP_MENU_BUTTON_04_ID), Bitmap(BITMAP_MENU_BUTTON_PRESSED_04_ID));
	
	int horizontalMenuItemWidth = bottomSlideMenuItems[0].getWidth();
	
	for (int i = 0; i < NUMBER_OF_MENU_ITEM_BUTTONS; i++)
    {
        // Add the buttons to the slide menu, placing them next to each other but with a gap
        int gapWidth = 16;
        bottomSlideMenuItems[i].setXY((i * horizontalMenuItemWidth) + (i * gapWidth), slideMenus[0].getBackgroundY() + 7);
        bottomSlideMenuItems[i].setAction(buttonClickedCallback);
        slideMenus[0].add(bottomSlideMenuItems[i]);
    }
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::buttonClicked()
{
    if(imagevisible)
    { 
        imagevisible = false;
		Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", TypedText(T_TEXTTOGGLEA).getText());
		textArea2.invalidate();
		touchgfx_printf("change background color to purple\n");
        box1.setColor(touchgfx::Color::getColorFrom24BitRGB(139, 12, 214));
        box1.invalidate();
        
    }
    else
    {
        imagevisible = true;
		Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", TypedText(T_TEXTTOGGLEB).getText());
		textArea2.invalidate();
        touchgfx_printf("change background color\n");
        box1.setColor(touchgfx::Color::getColorFrom24BitRGB(139, 120, 214));
        box1.invalidate();
    }
}

void Screen1View::slideMenuStateChangedHandler(const SlideMenu& slideMenu)
{
	
}

void Screen1View::buttonClickedHandler(const AbstractButton& button)
{
	
}
