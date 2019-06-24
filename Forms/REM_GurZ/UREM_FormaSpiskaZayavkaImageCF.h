#ifndef UREM_FormaSpiskaZayavkaImageCFH                  
#define UREM_FormaSpiskaZayavkaImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaZayavkaImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaZayavkaImageCF();                                                           
   ~TREM_FormaSpiskaZayavkaImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
