# File: Android.mk

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := NodeWrap
LOCAL_SRC_FILES := Node_wrap.cxx Node.cpp
LOCAL_LDLIBS += -latomic
LOCAL_CFLAGS    := -frtti -fexceptions

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := SmoothSortWrap
LOCAL_SRC_FILES := SmoothsortPriorityQueue_wrap.cxx SmoothsortPriorityQueue.cpp Node.cpp Astar.cpp
LOCAL_LDLIBS += -latomic
LOCAL_CFLAGS    := -frtti -fexceptions

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := AstarWrap
LOCAL_SRC_FILES := Astar_wrap.cxx Astar.cpp Node.cpp SmoothsortPriorityQueue.cpp
LOCAL_LDLIBS += -latomic
LOCAL_CFLAGS    := -frtti -fexceptions

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := DijkstraWrap
LOCAL_SRC_FILES := Dijkstra_wrap.cxx Dijkstra.cpp Node.cpp SmoothsortPriorityQueue.cpp
LOCAL_LDLIBS += -latomic
LOCAL_CFLAGS    := -frtti -fexceptions

include $(BUILD_SHARED_LIBRARY)


