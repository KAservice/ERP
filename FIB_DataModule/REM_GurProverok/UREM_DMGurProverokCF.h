#ifndef UREM_DMGurProverokCFH                  
#define UREM_DMGurProverokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurProverokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurProverokCF();                                                           
   ~TREM_DMGurProverokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
