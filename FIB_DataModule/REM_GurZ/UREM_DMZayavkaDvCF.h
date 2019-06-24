#ifndef UREM_DMZayavkaDvCFH                  
#define UREM_DMZayavkaDvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMZayavkaDvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMZayavkaDvCF();                                                           
   ~TREM_DMZayavkaDvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
