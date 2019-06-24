//---------------------------------------------------------------------------

#ifndef Ukas1CSystemH
#define Ukas1CSystemH
//---------------------------------------------------------------------------


//#include "vcl.h"
//#include <windows.h>
//#include <Classes.hpp>
#include "AddInDefBase.h"

//это интерфейс нашей программы, подменяющий интерфейс 1С

class Tkas1CSystem : public IAddInDefBase
{
private:
public:
		Tkas1CSystem();
		~Tkas1CSystem();



	/// Adds the error message
    /**
     *  @param wcode - error code
     *  @param source - source of error
     *  @param descr - description of error
     *  @param scode - error code (HRESULT)
     *  @return the result of
     */
	bool ADDIN_API AddError(unsigned short wcode, const WCHAR_T* source,
				    const WCHAR_T* descr, long scode);

    /// Reads a property value
    /**
     *  @param wszPropName -property name
     *  @param pVal - value being returned
     *  @param pErrCode - error code (if any error occured)
     *  @param errDescriptor - error description (if any error occured)
     *  @return the result of read.
     */
	bool ADDIN_API Read(WCHAR_T* wszPropName,
				tVariant* pVal,
				long *pErrCode,
				WCHAR_T** errDescriptor);
    /// Writes a property value
    /**
     *  @param wszPropName - property name
     *  @param pVar - new property value
     *  @return the result of write.
     */
	bool ADDIN_API Write(WCHAR_T* wszPropName,
				 tVariant *pVar);

    ///Registers profile components
    /**
     *  @param wszProfileName - profile name
     *  @return the result of
     */
	bool ADDIN_API RegisterProfileAs(WCHAR_T* wszProfileName);

    /// Changes the depth of event buffer
    /**
     *  @param lDepth - new depth of event buffer
     *  @return the result of
     */
	bool ADDIN_API SetEventBufferDepth(long lDepth);
	/// Returns the depth of event buffer
    /**
     *  @return the depth of event buffer
     */
	long ADDIN_API GetEventBufferDepth();
	/// Registers external event
    /**
     *  @param wszSource - source of event
     *  @param wszMessage - event message
     *  @param wszData - message parameters
     *  @return the result of
     */
	bool ADDIN_API ExternalEvent(WCHAR_T* wszSource,
					 WCHAR_T* wszMessage,
					 WCHAR_T* wszData);
	/// Clears event buffer
    /**
     */
	void ADDIN_API CleanEventBuffer();

    /// Sets status line contents
    /**
     *  @param wszStatusLine - new status line contents
     *  @return the result of
     */
	bool ADDIN_API SetStatusLine(WCHAR_T* wszStatusLine);
	/// Resets the status line contents
    /**
     *  @return the result of
     */
	void ADDIN_API ResetStatusLine();

};

#endif
