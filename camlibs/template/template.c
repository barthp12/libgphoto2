/** \file template.c
 * \brief Documented source code template for a camera driver (camlib).
 *
 * \author Copyright 2001 Lutz Mueller <lutz@users.sourceforge.net>
 * \author Copyright 2005 Hans Ulrich Niedermann <gp@n-dimensional.de>
 *
 * \par
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * \par
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * \section intro Introduction to camera drivers (camlibs)
 *
 * Every camlib must implement the following three function groups:
 *
 *   - Camera object member functions
 *   - CameraFilesystem object member functions
 *   - camlib API functions
 *
 * We implement the camlib API functions last in this file because
 * camera_init() must reference all the object member functions and by
 * making camera_init() the last function in this file, we can avoid
 * the need for forward declarations of the object member functions.
 *
 * \section linknote Note about "static" functions and exporting symbols
 *
 * The build system uses libtool to explicitly specify the list of
 * exported symbols. Only the three functions of the camlib API
 * (camera_init(), camera_id(), and camera_abilities()) are exported.
 *
 * Therefore it doesn't matter whether you declare your other
 * functions static or not - regardless of whether they are object
 * member functions or internal camlib functions.
 *
 * We do not define the object member functions as static in this
 * template in order to have autogenerated documentation about them.
 *
 */
#include "config.h"

#include <string.h>

#include <gphoto2/gphoto2-library.h>
#include <gphoto2/gphoto2-result.h>

#include "libgphoto2/i18n.h"


/**********************************************************************/
/**
 * @name Camera object member functions
 *
 * The prototypes for these functions are defined in gphoto2-camera.h
 *
 * @{
 */
/**********************************************************************/


/**
 * Finish up the camera communication and free
 * private data. You do not need to close the port.
 *
 * This function is a method of the Camera object.
 */
int camera_exit (Camera *camera, GPContext *context);
int
camera_exit (Camera *camera, GPContext *context)
{
	return GP_OK;
}


/**
 * Get the full configuration tree of the camera.
 *
 * This function is a method of the Camera object.
 */
int camera_config_get (Camera *camera, CameraWidget **window, GPContext *context);
int
camera_config_get (Camera *camera, CameraWidget **window, GPContext *context)
{
	gp_widget_new (GP_WIDGET_WINDOW, "Camera Configuration", window);

	/* Append your sections and widgets here. */

	return GP_OK;
}


/**
 * Set parts of the configuration tree. Note that you get
 * back the whole tree, but should only set the modified
 * values.
 *
 * This function is a method of the Camera object.
 */
int camera_config_set (Camera *camera, CameraWidget *window, GPContext *context);
int
camera_config_set (Camera *camera, CameraWidget *window, GPContext *context)
{
	/*
	 * Check if the widgets' values have changed. If yes, tell the camera.
	 */

	return GP_OK;
}


/**
 * Capture a preview and return the data in the given file (again,
 * use gp_file_set_data_and_size, gp_file_set_mime_type, etc.).
 * libgphoto2 assumes that previews are NOT stored on the camera's
 * disk. If your camera does, please delete it from the camera.
 *
 * This function is a method of the Camera object.
 */
int camera_capture_preview (Camera *camera, CameraFile *file, GPContext *context);
int
camera_capture_preview (Camera *camera, CameraFile *file, GPContext *context)
{
	return GP_OK;
}


/**
 * Capture an image and tell libgphoto2 where to find it by filling
 * out the path.
 *
 * This function is a method of the Camera object.
 */
int
camera_capture (Camera *camera, CameraCaptureType type, CameraFilePath *path,
		GPContext *context);
int
camera_capture (Camera *camera, CameraCaptureType type, CameraFilePath *path,
		GPContext *context)
{
	return GP_OK;
}


/**
 * Fill out the summary with textual information about the current
 * state of the camera (like pictures taken, etc.).
 *
 * This function is a method of the Camera object.
 */
int
camera_summary (Camera *camera, CameraText *summary, GPContext *context);
int
camera_summary (Camera *camera, CameraText *summary, GPContext *context)
{
	return GP_OK;
}


/**
 * Return the camera drivers manual.
 * If you would like to tell the user some information about how
 * to use the camera or the driver, this is the place to do.
 *
 * This function is a method of the Camera object.
 */
int
camera_manual (Camera *camera, CameraText *manual, GPContext *context);
int
camera_manual (Camera *camera, CameraText *manual, GPContext *context)
{
	return GP_OK;
}


/**
 * Return "About" content as textual description.
 * Will be translated.
 *
 * This function is a method of the Camera object.
 */
int
camera_about (Camera *camera, CameraText *about, GPContext *context);
int
camera_about (Camera *camera, CameraText *about, GPContext *context)
{
	strcpy (about->text, _("Library Name\n"
			       "YOUR NAME <email@somewhere.com>\n"
			       "Quick description of the library.\n"
			       "No more than 5 lines if possible."));

	return GP_OK;
}

/*@}*/


/**********************************************************************/
/**
 * @name CameraFilesystem member functions
 *
 * @{
 */
/**********************************************************************/


/**
 * Get the file from the camera.
 *
 * This function is a CameraFilesystem method.
 */
int
get_file_func (CameraFilesystem *fs, const char *folder, const char *filename,
	       CameraFileType type, CameraFile *file, void *data,
	       GPContext *context);
int
get_file_func (CameraFilesystem *fs, const char *folder, const char *filename,
	       CameraFileType type, CameraFile *file, void *data,
	       GPContext *context)
{
	/*Camera *camera = data;*/

	/*
	 * Get the file from the camera. Use gp_file_set_mime_type,
	 * gp_file_set_data_and_size, etc.
	 */

	return GP_OK;
}


/**
 * Put a file onto the camera.
 *
 * This function is a CameraFilesystem method.
 */
int
put_file_func (CameraFilesystem *fs, const char *folder, const char *name,
	       CameraFileType type, CameraFile *file, void *data, GPContext *context);
int
put_file_func (CameraFilesystem *fs, const char *folder, const char *name,
	       CameraFileType type, CameraFile *file, void *data, GPContext *context)
{
	/*Camera *camera = data;*/

	/*
	 * Upload the file to the camera. Use gp_file_get_data_and_size, etc
	 */

	return GP_OK;
}


/**
 * Delete a file from the camera.
 *
 * This function is a CameraFilesystem method.
 */
int
delete_file_func (CameraFilesystem *fs, const char *folder,
		  const char *filename, void *data, GPContext *context);
int
delete_file_func (CameraFilesystem *fs, const char *folder,
		  const char *filename, void *data, GPContext *context)
{
	/*Camera *camera = data;*/

	/* Delete the file from the camera. */

	return GP_OK;
}


/**
 * Delete all files from the camera.
 *
 * This function is a CameraFilesystem method.
 */
int
delete_all_func (CameraFilesystem *fs, const char *folder, void *data,
		 GPContext *context);
int
delete_all_func (CameraFilesystem *fs, const char *folder, void *data,
		 GPContext *context)
{
	/*Camera *camera = data;*/

	/*
	 * Delete all files in the given folder. If your camera doesn't have
	 * such a functionality, just don't implement this function.
	 */

	return GP_OK;
}


/**
 * Get the file info here and write it to space provided by caller.
 *
 * \param info Space provided by caller in which file info is written.
 *
 * This function is a CameraFilesystem method.
 */
int
get_info_func (CameraFilesystem *fs, const char *folder, const char *filename,
	       CameraFileInfo *info, void *data, GPContext *context);
int
get_info_func (CameraFilesystem *fs, const char *folder, const char *filename,
	       CameraFileInfo *info, void *data, GPContext *context)
{
	/*Camera *camera = data;*/

	return GP_OK;
}


/**
 * FIXME.
 *
 * This function is a CameraFilesystem method.
 */
int
set_info_func (CameraFilesystem *fs, const char *folder, const char *file,
	       CameraFileInfo info, void *data, GPContext *context);
int
set_info_func (CameraFilesystem *fs, const char *folder, const char *file,
	       CameraFileInfo info, void *data, GPContext *context)
{
	/*Camera *camera = data;*/

	/* Set the file info here from <info> */

	return GP_OK;
}


/**
 * List available folders in the specified folder.
 *
 * This function is a CameraFilesystem method.
 */
int
folder_list_func (CameraFilesystem *fs, const char *folder, CameraList *list,
		  void *data, GPContext *context);
int
folder_list_func (CameraFilesystem *fs, const char *folder, CameraList *list,
		  void *data, GPContext *context)
{
	/*Camera *camera = data;*/

	/* List your folders here */

	return GP_OK;
}


/**
 * List available files in the specified folder.
 *
 * This function is a CameraFilesystem method.
 */
int
file_list_func (CameraFilesystem *fs, const char *folder, CameraList *list,
		void *data, GPContext *context);
int
file_list_func (CameraFilesystem *fs, const char *folder, CameraList *list,
		void *data, GPContext *context)
{
	/*Camera *camera = data;*/

	/* List your files here */

	return GP_OK;
}

/**
 * Get information on all available storages in the camera.
 *
 * This function is a CameraFilesystem method.
 */
int
storage_info_func (CameraFilesystem *fs,
		CameraStorageInformation **storageinformations,
		int *nrofstorageinformations, void *data,
		GPContext *context);
int
storage_info_func (CameraFilesystem *fs,
		CameraStorageInformation **storageinformations,
		int *nrofstorageinformations, void *data,
		GPContext *context)
{
	/*Camera *camera = data;*/

	/* List your storages here */

	return GP_ERROR_NOT_SUPPORTED;
}

/*@}*/


/**********************************************************************/
/**
 * @name camlib API functions
 *
 * @{
 */
/**********************************************************************/


/**
 * Set library ID string.
 *
 * Probably redundant and to be removed shortly, being replaced
 * by the libtool module name defined in the build system.
 *
 * This is a camlib API function.
 */
int
camera_id (CameraText *id)
{
	strcpy(id->text, "REPLACE WITH UNIQUE LIBRARY ID");

	return GP_OK;
}


/**
 * Fill list with abilities of the cameras supported by this camlib.
 *
 * For each camera, fill a CameraAbilities structure with data about
 * that camera and append it to the list.
 *
 * The job of this function is  basically to extract data from a
 * camlib specific database and insert it into the libgphoto2 camera
 * database. Due to redundant data and other issues, we may decide to
 * revise that database mechanism and replace it by something more
 * flexible and efficient.
 *
 * This is a camlib API function.
 */
int
camera_abilities (CameraAbilitiesList *list)
{
	CameraAbilities a;

	memset(&a, 0, sizeof(a));
	strcpy(a.model, "CAMERA VENDOR:CAMERA MODEL");
	a.status = GP_DRIVER_STATUS_PRODUCTION;
	a.port     = GP_PORT_SERIAL | GP_PORT_USB;
	a.speed[0] = 0;
	a.operations        = 	GP_OPERATION_CAPTURE_PREVIEW |
				GP_CAPTURE_IMAGE;
	a.file_operations   = 	GP_FILE_OPERATION_DELETE |
				GP_FILE_OPERATION_PREVIEW;
	a.folder_operations = 	GP_FOLDER_OPERATION_NONE;

	gp_abilities_list_append(list, a);

	return GP_OK;
}

/**
 * All filesystem accessor functions.
 *
 * This should contain all filesystem accessor functions
 * available in the camera library. Non-present fields
 * are NULL.
 *
 */
CameraFilesystemFuncs fsfuncs = {
	.file_list_func = file_list_func,
	.folder_list_func = folder_list_func,
	.get_info_func = get_info_func,
	.set_info_func = set_info_func,
	.get_file_func = get_file_func,
	.del_file_func = delete_file_func,
	.put_file_func = put_file_func,
	.delete_all_func = delete_all_func,
	.storage_info_func = storage_info_func
};

/**
 * Initialize a Camera object.
 *
 * Sets up all the proper object function pointers, initialize camlib
 * internal data structures, and probably establish a connection to
 * the camera.
 *
 * This is a camlib API function.
 */
int
camera_init (Camera *camera, GPContext *context)
{
        /* First, set up all the function pointers */
        camera->functions->exit                 = camera_exit;
        camera->functions->get_config           = camera_config_get;
        camera->functions->set_config           = camera_config_set;
        camera->functions->capture              = camera_capture;
        camera->functions->capture_preview      = camera_capture_preview;
        camera->functions->summary              = camera_summary;
        camera->functions->manual               = camera_manual;
        camera->functions->about                = camera_about;

	/* Now, tell the filesystem where to get lists, files and info */
	gp_filesystem_set_funcs (camera->fs, &fsfuncs, camera);

	/*
	 * The port is already provided with camera->port (and
	 * already open). You just have to use functions like
	 * gp_port_timeout_set, gp_port_settings_get, gp_port_settings_set.
	 */

	/*
	 * Once you have configured the port, you should check if a
	 * connection to the camera can be established.
	 */

	return GP_OK;
}

/*@}*/


/*********************************************************************
 * End of camlib template.
 *********************************************************************/

/*
 * Local Variables:
 * c-file-style:"linux"
 * indent-tabs-mode:t
 * End:
 */
