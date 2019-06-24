#ifndef UREM_DMGurCustQueryCFH                  
#define UREM_DMGurCustQueryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurCustQueryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurCustQueryCF();                                                           
   ~TREM_DMGurCustQueryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
