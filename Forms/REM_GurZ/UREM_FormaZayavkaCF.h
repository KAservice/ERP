#ifndef UREM_FormaZayavkaCFH                  
#define UREM_FormaZayavkaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaZayavkaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaZayavkaCF();                                                           
   ~TREM_FormaZayavkaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
