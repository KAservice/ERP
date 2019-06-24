#ifndef UREM_FormaDocKM2CFH                  
#define UREM_FormaDocKM2CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocKM2CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocKM2CF();                                                           
   ~TREM_FormaDocKM2CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
