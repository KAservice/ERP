//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasMemoryManager.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//--------------------------------------------------------------------------
TkasMemoryManager::TkasMemoryManager()
{

}
//-----------------------------------------------------------------------------
TkasMemoryManager::~TkasMemoryManager()
{
//FreeLibrary(dllIn);
}
//---------------------------------------------------------------------------

		    /// Allocates memory of specified size
     /**
     *  @param pMemory - the double pointer to variable, that will hold newly
     *      allocated block of memory of NULL if allocation fails.
     *  @param ulCountByte - memory size
     *  @return the result of
     */
bool ADDIN_API TkasMemoryManager::AllocMemory (void** pMemory, unsigned long ulCountByte)
//��� ������ ������ ADDIN_IPI �� __stdcall ���� ���������� ��������� _WINDOWS
{
bool result=true;

int* p=0;
p=new int[ulCountByte];
*pMemory=p;   //!!!!!!!!!!!!!!!!!!!��� ���������� ����������� ��������� ������������!!!!!!!!!!!!!!!!

return result;
}
//----------------------------------------------------------------------------



	/// Releases memory
     /**
	 *  @param pMemory - The double pointer to the memory block being released
     */
void ADDIN_API TkasMemoryManager::FreeMemory (void** pMemory)
{

delete pMemory;
}
//---------------------------------------------------------------------------
