#ifndef UREM_DMGurVigrusokCFH                  
#define UREM_DMGurVigrusokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurVigrusokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurVigrusokCF();                                                           
   ~TREM_DMGurVigrusokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
