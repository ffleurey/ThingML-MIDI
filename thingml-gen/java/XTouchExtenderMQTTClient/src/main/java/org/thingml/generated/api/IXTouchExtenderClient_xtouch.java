package org.thingml.generated.api;

import org.thingml.generated.api.*;

public interface IXTouchExtenderClient_xtouch{
void slider_via_xtouch(int XTouchExtenderMsgs_slider_ch_var, int XTouchExtenderMsgs_slider_value_var);
void pot_via_xtouch(int XTouchExtenderMsgs_pot_ch_var, int XTouchExtenderMsgs_pot_value_var);
void button_press_via_xtouch(int XTouchExtenderMsgs_button_press_ch_var, int XTouchExtenderMsgs_button_press_id_var);
void button_release_via_xtouch(int XTouchExtenderMsgs_button_release_ch_var, int XTouchExtenderMsgs_button_release_id_var);
}