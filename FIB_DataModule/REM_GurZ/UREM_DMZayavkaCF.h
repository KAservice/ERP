#ifndef UREM_DMZayavkaCFH                  
#define UREM_DMZayavkaCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMZayavkaCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMZayavkaCF();                                                           
   ~TREM_DMZayavkaCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
