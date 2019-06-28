#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View() : imagevisible(true)
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
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
        touchgfx_printf("hide image \n");
        image.setVisible(false);
        image.invalidate();        
    }
    else
    {
        imagevisible = true;
        touchgfx_printf("show image \n");
        image.setVisible(true);
        image.invalidate();
    }
}