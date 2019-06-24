//---------------------------------------------------------------------------

#ifndef UkasMemoryManagerH
#define UkasMemoryManagerH
//---------------------------------------------------------------------------
//это наш аналог менеджера пам€ти 1с предпри€ти€
#include "types.h"
#include "IMemoryManager.h"

class TkasMemoryManager : public IMemoryManager
{
private:
public:
		TkasMemoryManager();
		~TkasMemoryManager();



		    /// Allocates memory of specified size
     /**
     *  @param pMemory - the double pointer to variable, that will hold newly
     *      allocated block of memory of NULL if allocation fails.
     *  @param ulCountByte - memory size
     *  @return the result of
     */
	bool ADDIN_API AllocMemory (void** pMemory, unsigned long ulCountByte);                  //это просто замена ADDIN_IPI на __stdcall если определена константа _WINDOWS
    /// Releases memory
     /**
	 *  @param pMemory - The double pointer to the memory block being released
     */
	void ADDIN_API FreeMemory (void** pMemory);

};



#endif
