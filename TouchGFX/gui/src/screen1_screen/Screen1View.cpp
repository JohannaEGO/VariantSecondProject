#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

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
		touchgfx_printf("change background color to purple\n");
        box1.setColor(touchgfx::Color::getColorFrom24BitRGB(139, 12, 214));
        box1.invalidate();
        
    }
    else
    {
        imagevisible = true;
        touchgfx_printf("change background color\n");
        box1.setColor(touchgfx::Color::getColorFrom24BitRGB(139, 120, 214));
        box1.invalidate();
    }
}