#ifndef _SHIPCPANEL_H
#define _SHIPCPANEL_H

#include "libs.h"
#include "Gui.h"
#include "ShipCpanelMultiFuncDisplays.h"

class Body;
class SpaceStation;

class ShipCpanel: public Gui::Fixed {
public:
	ShipCpanel();
	virtual ~ShipCpanel();
	virtual void Draw();
	void Update();
	MsgLogWidget *MsgLog() { return m_msglog; }
private:
	void OnChangeCamView(Gui::MultiStateImageButton *b);
	void OnChangeMapView(Gui::MultiStateImageButton *b);
	void OnChangeInfoView(Gui::MultiStateImageButton *b);
	void OnClickTimeaccel(int val);
	void OnClickComms(Gui::MultiStateImageButton *b);
	void OnDockingClearanceExpired(const SpaceStation *);
	void OnUserChangeMultiFunctionDisplay(multifuncfunc_t f);
	void ChangeMultiFunctionDisplay(Gui::Widget *selected);
	void OnMultiFuncGrabFocus(Gui::Widget *);
	void OnMultiFuncUngrabFocus(Gui::Widget *);

	Gui::Widget *m_userSelectedMfuncWidget;
	Gui::Label *m_clock;

	sigc::connection m_connOnDockingClearanceExpired;

	ScannerWidget *m_scanner;
	MsgLogWidget *m_msglog;
	Gui::ImageRadioButton *m_timeAccelButtons[6];
};

#endif /* _SHIP_CPANEL_H */
