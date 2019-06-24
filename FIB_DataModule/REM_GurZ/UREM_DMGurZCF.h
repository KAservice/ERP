#ifndef UREM_DMGurZCFH                  
#define UREM_DMGurZCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurZCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurZCF();                                                           
   ~TREM_DMGurZCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
