#ifndef UREM_DMZayavkaImageCFH                  
#define UREM_DMZayavkaImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMZayavkaImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMZayavkaImageCF();                                                           
   ~TREM_DMZayavkaImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
