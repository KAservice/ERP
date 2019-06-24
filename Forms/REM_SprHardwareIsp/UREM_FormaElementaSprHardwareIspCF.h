#ifndef UREM_FormaElementaSprHardwareIspCFH                  
#define UREM_FormaElementaSprHardwareIspCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaElementaSprHardwareIspCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaElementaSprHardwareIspCF();                                                           
   ~TREM_FormaElementaSprHardwareIspCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
