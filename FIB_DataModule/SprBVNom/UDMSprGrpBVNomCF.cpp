#include <vcl.h>
#pragma hdrstop
#include "UDMSprGrpBVNomCF.h"   
#include "UDMSprGrpBVNomImpl.h"  
#include "IDMSprGrpBVNom.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
TDMSprGrpBVNomCF::TDMSprGrpBVNomCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
TDMSprGrpBVNomCF::~TDMSprGrpBVNomCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int TDMSprGrpBVNomCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();
return result;  
}   
//---------------------------------------------------------------
int TDMSprGrpBVNomCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int TDMSprGrpBVNomCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;
	return 0;
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int TDMSprGrpBVNomCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		TDMSprGrpBVNomImpl * ob=new TDMSprGrpBVNomImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
