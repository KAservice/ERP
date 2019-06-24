#ifndef UREM_DMSprHardwareIspCFH                  
#define UREM_DMSprHardwareIspCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprHardwareIspCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprHardwareIspCF();                                                           
   ~TREM_DMSprHardwareIspCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
