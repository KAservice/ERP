#ifndef UREM_DMSprModelDetalCFH                  
#define UREM_DMSprModelDetalCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMSprModelDetalCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMSprModelDetalCF();                                                           
   ~TREM_DMSprModelDetalCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
