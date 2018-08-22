//
//  ButtonSample.cpp
//  gui
//
//  Created by working on 2018/8/20.
//  Copyright © 2018年 working. All rights reserved.
//

#include "ButtonSample.hpp"

namespace gc {
    using namespace std;
    
    void click() {
        cout << "btn click" << endl;
    }
    
    void ButtonSample1() {
        int w = 800;
        int h = 600;
        
        GcGui gui(w, h, "sss");
        
        GcRect rect(10, 10, 700, 550);
        GcColor viewColor(255, 255, 255, 255);
        
        GuiView view(rect, viewColor);
        gui.AddView(&view);
        
        // button
        GcRect btnRect(50, 50, 100, 30);
        GcColor btnColor(12, 12, 100, 255);
        GuiButton btn(btnRect, btnColor);
        btn.OnButtonDown = &click;
        btn.renderer = view.renderer;
        
        // image
        GcRect imgRect(150, 50, 100, 100);
        GcColor imgColor(12, 12, 100, 255);
        GuiImage img(imgRect, imgColor);
        img.renderer = view.renderer;
        
        // radio
        GcRect radioRect(50, 100, 30, 30);
        GcColor radioColor(120, 120, 100, 255);
        GcColor radioCheckidColor(12, 120, 100, 255);
        GuiRadio radio(radioRect, radioColor, radioCheckidColor);
        radio.renderer = view.renderer;
        
        // input
//        GcRect inputRect(50, 100, 30, 30);
//        GcColor inputColor(120, 120, 100, 255);
//        GcColor inputCheckidColor(12, 120, 100, 255);
//        GuiInput input(inputRect, inputColor, inputCheckidColor);
//        input.renderer = view.renderer;
        
        // label
        GcRect labelRect(50, 100, 30, 30);
        GcColor labelColor(120, 120, 100, 255);
        GuiLabel label(labelRect, labelColor, "labelCheckidColor");
        label.renderer = view.renderer;
        
        // add
        view.AddElements(&btn);
        view.AddElements(&img);
        view.AddElements(&radio);
        view.AddElements(&label);
//        view.AddElements(&input);
        
        gui.run();
    }

}

