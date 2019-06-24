#ifndef UREM_DMZayavkaPredvCFH                  
#define UREM_DMZayavkaPredvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMZayavkaPredvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMZayavkaPredvCF();                                                           
   ~TREM_DMZayavkaPredvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
