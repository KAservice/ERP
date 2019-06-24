#ifndef UREM_DMSprGrpHardwareCFH                  
#define UREM_DMSprGrpHardwareCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprGrpHardwareCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprGrpHardwareCF();                                                           
   ~TREM_DMSprGrpHardwareCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
