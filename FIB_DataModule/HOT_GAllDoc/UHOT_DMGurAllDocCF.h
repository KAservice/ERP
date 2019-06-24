#ifndef UHOT_DMGurAllDocCFH                  
#define UHOT_DMGurAllDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMGurAllDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMGurAllDocCF();                                                           
   ~THOT_DMGurAllDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
