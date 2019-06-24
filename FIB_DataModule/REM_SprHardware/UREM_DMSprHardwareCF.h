#ifndef UREM_DMSprHardwareCFH                  
#define UREM_DMSprHardwareCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprHardwareCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprHardwareCF();                                                           
   ~TREM_DMSprHardwareCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
