#pragma once

#include "GLView.h"

namespace Aftr
{
   class Camera;

/**
   \class GLViewSoundProject
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewSoundProject : public GLView
{
public:
   static GLViewSoundProject* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewSoundProject();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createSoundProjectWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   void init( float gravityScalar = Aftr::GRAVITY, 
		   Vector gravityNormalizedVector = Vector(0,0,-1),
		   std::string confFileName = "Aftr.conf", 
		   const PHYSICS_ENGINE_TYPE& physicsEngineType = PHYSICS_ENGINE_TYPE::petODE);
   void shutdownEngine();
   
   bool trigger_flag;

protected:
   GLViewSoundProject( const std::vector< std::string >& args );
   virtual void onCreate();

   WO* track_sphere;
};

/** \} */

} //namespace Aftr
