#ifndef UREM_FormaDocKM1CFH                  
#define UREM_FormaDocKM1CFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocKM1CF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocKM1CF();                                                           
   ~TREM_FormaDocKM1CF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
