//---------------------------------------------------------------------------


#pragma hdrstop

#include "Ukas1CSystem.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
Tkas1CSystem::Tkas1CSystem()
{

}
//-----------------------------------------------------------------------------
Tkas1CSystem::~Tkas1CSystem()
{
//FreeLibrary(dllIn);
}
//---------------------------------------------------------------------------

    /// Adds the error message
    /**
     *  @param wcode - error code
     *  @param source - source of error
     *  @param descr - description of error
     *  @param scode - error code (HRESULT)
     *  @return the result of
     */
bool ADDIN_API Tkas1CSystem::AddError(unsigned short wcode, const WCHAR_T* source,
					const WCHAR_T* descr, long scode)
{
bool result=true;


return result;
}
//----------------------------------------------------------------------------

    /// Reads a property value
    /**
     *  @param wszPropName -property name
     *  @param pVal - value being returned
     *  @param pErrCode - error code (if any error occured)
     *  @param errDescriptor - error description (if any error occured)
     *  @return the result of read.
	 */
bool ADDIN_API Tkas1CSystem::Read(WCHAR_T* wszPropName,
				tVariant* pVal,
				long *pErrCode,
				WCHAR_T** errDescriptor)

{
bool result=true;


return result;
}
//----------------------------------------------------------------------------
    /// Writes a property value
    /**
     *  @param wszPropName - property name
     *  @param pVar - new property value
     *  @return the result of write.
     */
bool ADDIN_API Tkas1CSystem::Write(WCHAR_T* wszPropName,
				 tVariant *pVar)

{
bool result=true;


return result;
}
//----------------------------------------------------------------------------

    ///Registers profile components
    /**
     *  @param wszProfileName - profile name
     *  @return the result of
     */
bool ADDIN_API Tkas1CSystem::RegisterProfileAs(WCHAR_T* wszProfileName)

{
bool result=true;


return result;
}
//----------------------------------------------------------------------------

    /// Changes the depth of event buffer
    /**
     *  @param lDepth - new depth of event buffer
     *  @return the result of
     */
bool ADDIN_API Tkas1CSystem::SetEventBufferDepth(long lDepth)

{
bool result=true;


return result;
}
//----------------------------------------------------------------------------
	/// Returns the depth of event buffer
    /**
     *  @return the depth of event buffer
     */
long ADDIN_API Tkas1CSystem::GetEventBufferDepth()

{
long result=1;


return result;
}
//----------------------------------------------------------------------------
    /// Registers external event
    /**
     *  @param wszSource - source of event
     *  @param wszMessage - event message
     *  @param wszData - message parameters
     *  @return the result of
     */
bool ADDIN_API Tkas1CSystem::ExternalEvent(WCHAR_T* wszSource,
					 WCHAR_T* wszMessage,
					 WCHAR_T* wszData)

{
bool result=true;


return result;
}
//----------------------------------------------------------------------------
    /// Clears event buffer
    /**
     */
void ADDIN_API Tkas1CSystem::CleanEventBuffer()

{
int i=1;
}
//----------------------------------------------------------------------------

    /// Sets status line contents
    /**
     *  @param wszStatusLine - new status line contents
     *  @return the result of
	 */
bool ADDIN_API Tkas1CSystem::SetStatusLine(WCHAR_T* wszStatusLine)

{
bool result=true;


return result;
}
//----------------------------------------------------------------------------
    /// Resets the status line contents
    /**
     *  @return the result of
     */
void ADDIN_API Tkas1CSystem::ResetStatusLine()

{
int i=1;
}
//----------------------------------------------------------------------------