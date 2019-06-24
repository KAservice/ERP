#ifndef UREM_DMGurZPredvCFH                  
#define UREM_DMGurZPredvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMGurZPredvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMGurZPredvCF();                                                           
   ~TREM_DMGurZPredvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
