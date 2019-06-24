#ifndef UREM_FormaZayavkaPredvCFH                  
#define UREM_FormaZayavkaPredvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaZayavkaPredvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaZayavkaPredvCF();                                                           
   ~TREM_FormaZayavkaPredvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
