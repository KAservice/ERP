#ifndef UREM_DMSprModel2CFH                  
#define UREM_DMSprModel2CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprModel2CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprModel2CF();                                                           
   ~TREM_DMSprModel2CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
