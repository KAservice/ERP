#ifndef UREM_DMSprActCategoryCFH                  
#define UREM_DMSprActCategoryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprActCategoryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprActCategoryCF();                                                           
   ~TREM_DMSprActCategoryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
