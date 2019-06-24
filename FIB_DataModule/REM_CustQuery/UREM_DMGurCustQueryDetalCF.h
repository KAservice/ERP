#ifndef UREM_DMGurCustQueryDetalCFH                  
#define UREM_DMGurCustQueryDetalCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurCustQueryDetalCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurCustQueryDetalCF();                                                           
   ~TREM_DMGurCustQueryDetalCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
