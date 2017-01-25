#ifndef MENUBAR_MENU_BAR_H
#define MENUBAR_MENU_BAR_H

#include <cocos2d.h>
#include <ui/CocosGUI.h>
#include "padding.h"
#include "items_bar.h"

namespace menubar {

///
/// MenuBar class.
///
class MenuBar: public cocos2d::ui::Widget {
protected:
  MenuBar(const Padding &padding, float items_gap);
  
public:
  static MenuBar *create(const Padding &padding = {10, 16, 10, 16}, float items_gap = 16);
  virtual ~MenuBar() {}
  virtual bool init() override;
  virtual void onSizeChanged() override;
  void AddBackground(cocos2d::ui::Widget *background);
  void AddLeftComponent(cocos2d::ui::Widget *component, unsigned int index = -1);
  void AddRightComponent(cocos2d::ui::Widget *component, unsigned int index = -1);

private:
  void DoInit();
  void SetDefaultSize();
  void InitLeftItems();
  void InitRightItems();
  void PositionLeftItems();
  void PositionRightItems();
  float available_height() const;

  void RemoveBackground();
  void AddBackground();
  void FitBackground();

private:
  Padding padding_;
  float items_gap_;
  cocos2d::ui::Widget *background_ = nullptr;
  ItemsBar *left_items_ = nullptr;
  ItemsBar *right_items_ = nullptr;
};

}

#endif
