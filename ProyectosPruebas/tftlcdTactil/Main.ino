

#include <XibXcreen.h>
#include <XibInterface.h>
#include <XibFrame.h>
#include <XibComponent.h>


TouchScreen XibXcreen::ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_TFTLCD XibXcreen::tft = Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TSPoint XibXcreen::tsp;

XibInterface xcn;
    XibBoton b;
void setup()
{
    Serial.begin(9600);
    XibXcreen::tft.reset();
    XibXcreen::tft.begin(MODEL);
    XibXcreen::tft.setRotation(3);

    XibFrame m;
    m.setColor(GREEN);
    m.setColor(RED);
    m.setMaxLayers(2);


    b.setCoor(50,6,100,100);
    b.setLayer(1);

    m.addComponent(b);
    xcn.addFrame(m);


    xcn.drawFrame(0);
    /*
    scn.init(&ts, &tft, &tsp);
    Frame *m;
    m->init(&ts, &tft, &tsp);
    m->setColor(YELLOW);
    scn.addFrame(m);
    tft.setRotation(0);
    scn.drawFrame(0);
    */
}

void loop()
{
    
    xcn.refreshTouchValues();
    
    int x1 = XibXcreen::tsp.x;
    int y1 = XibXcreen::tsp.y;

    if (b.CoorInsideMe(x1,y1))
    {
        //tft.fillCircle(x1,y1,3,BLACK);
    Serial.println("HOLA");
        int x2 = LONG_SIDE / 2;
        int y2 = SHORT_SIDE / 2;
        int xf = x1 - x2;
        int yf = y1 - y2;
        int d = sqrt(pow((xf), 2) + pow((yf), 2));

        //scn.tft.drawCircle(x2, y2, d, BLACK);

        XibXcreen::tft.fillRect(0, LONG_SIDE - 30, 240 / 3, LONG_SIDE, YELLOW);
        XibXcreen::tft.fillRect(240 / 3, LONG_SIDE - 30, 240 / 3 * 2, LONG_SIDE, BLACK);
        XibXcreen::tft.fillRect(240 / 3 * 2, LONG_SIDE - 30, 240 / 3 * 3, LONG_SIDE, MAGENTA);
    }
    //tft.fillCircle(x1, y1, 3, BLACK);
    
}
