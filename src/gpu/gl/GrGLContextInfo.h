/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef GrGLContextInfo_DEFINED
#define GrGLContextInfo_DEFINED

#include "gl/GrGLExtensions.h"
#include "gl/GrGLInterface.h"
#include "GrGLCaps.h"
#include "GrGLSL.h"
#include "GrGLUtil.h"

#include "SkString.h"

/**
 * Encapsulates information about an OpenGL context including the GrGLInterface
 * used to make GL calls, the OpenGL version, the GrGLBinding type of the
 * context, and GLSL version.
 */
class GrGLContextInfo {
public:

    /**
     * Default constructor, creates an uninitialized GrGLContextInfo
     */
    GrGLContextInfo();

    /**
     * Creates a GrGLContextInfo from a GrGLInterface and the currently
     * bound OpenGL context accessible by the GrGLInterface.
     */
    explicit GrGLContextInfo(const GrGLInterface* interface);

    /**
     * Copies a GrGLContextInfo
     */
    GrGLContextInfo(const GrGLContextInfo& ctx);

    ~GrGLContextInfo();

    /**
     * Copies a GrGLContextInfo
     */
    GrGLContextInfo& operator = (const GrGLContextInfo& ctx);

    /**
     * Initializes a GrGLContextInfo from a GrGLInterface and the currently
     * bound OpenGL context accessible by the GrGLInterface.
     */
    bool initialize(const GrGLInterface* interface);
    bool isInitialized() const;

    const GrGLInterface* interface() const { return fInterface; }
    GrGLBinding binding() const { return fBindingInUse; }
    GrGLVersion version() const { return fGLVersion; }
    GrGLSLGeneration glslGeneration() const { return fGLSLGeneration; }
    GrGLVendor vendor() const { return fVendor; }
    const GrGLCaps& caps() const { return fGLCaps; }
    GrGLCaps& caps() { return fGLCaps; }

    /**
     * Checks for extension support using a cached copy of the GL_EXTENSIONS
     * string.
     */
    bool hasExtension(const char* ext) const {
        if (!this->isInitialized()) {
            return false;
        }
        return fExtensions.has(ext);
    }

private:
    void reset();

    const GrGLInterface* fInterface;
    GrGLBinding          fBindingInUse;
    GrGLVersion          fGLVersion;
    GrGLSLGeneration     fGLSLGeneration;
    GrGLVendor           fVendor;
    GrGLExtensions       fExtensions;
    GrGLCaps             fGLCaps;
};

#endif
