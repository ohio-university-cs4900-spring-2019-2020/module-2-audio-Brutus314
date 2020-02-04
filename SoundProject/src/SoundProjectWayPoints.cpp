#include "WOWayPointAbstract.h"
#include "SoundProjectWayPoints.h"
#include "GLViewSoundProject.h"
#include "ManagerGLView.h"
#include <vector>
#include <iostream>

namespace Aftr
{

WOWP1* WOWP1::New(const WayPointParametersBase& params, float radius )
{
   WOWP1* ptr = new WOWP1(params, radius);
   ptr->onCreate();
   return ptr;
}

WOWP1::WOWP1(const WayPointParametersBase& params, float radius
             ) : WOWayPointSpherical( params, radius ), IFace( this )
{
}

WOWP1::~WOWP1()
{
}

void WOWP1::onTrigger()
{
   GLViewSoundProject* view = ManagerGLView::getGLView<GLViewSoundProject>();
   view->trigger_flag = true;
   std::cout << "WOWP1 waypoint Triggered, WAKA WAKA!" << std::endl << std::endl;
   this->permDisable();
}

} //namespace Aftr