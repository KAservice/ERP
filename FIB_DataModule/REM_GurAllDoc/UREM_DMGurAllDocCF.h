#ifndef UREM_DMGurAllDocCFH                  
#define UREM_DMGurAllDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurAllDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurAllDocCF();                                                           
   ~TREM_DMGurAllDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
