#include "bladewindow.h"
#include <QDebug>
#include <QString>

BladeWindow::~BladeWindow()
{
  makeCurrent();
  teardownGL();
}

/*******************************************************************************
 * OpenGL Events
 ******************************************************************************/

void BladeWindow::initializeGL()
{
  // Initialize OpenGL Backend
  initializeOpenGLFunctions();
  printContextInformation();

  // Set global information
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void BladeWindow::resizeGL(int width, int height)
{
  // Currently we are not handling width/height changes
  (void)width;
  (void)height;
}

void BladeWindow::paintGL()
{
  // Clear
  glClear(GL_COLOR_BUFFER_BIT);
}

void BladeWindow::teardownGL()
{
  // Currently we have no data to teardown
}

/*******************************************************************************
 * Private Helpers
 ******************************************************************************/

void BladeWindow::printContextInformation()
{
  QString glType;
  QString glVersion;
  QString glProfile;

  // Get Version Information
  glType = (context()->isOpenGLES()) ? "OpenGL ES" : "OpenGL";
  glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));

  // Get Profile Information
#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
  switch (format().profile())
  {
    CASE(NoProfile);
    CASE(CoreProfile);
    CASE(CompatibilityProfile);
  }
#undef CASE

  // qPrintable() will print our QString w/o quotes around it.
  qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";
}
